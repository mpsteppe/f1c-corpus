#include "f1c/config/ini_document.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <stdexcept>

namespace {

std::string trim(std::string value) {
    const auto whitespace = [](unsigned char character) {
        return std::isspace(character) != 0;
    };
    value.erase(value.begin(), std::find_if_not(value.begin(), value.end(), whitespace));
    value.erase(std::find_if_not(value.rbegin(), value.rend(), whitespace).base(), value.end());
    return value;
}

}  // namespace

namespace f1c::config {

IniDocument IniDocument::load(const std::filesystem::path& path) {
    std::ifstream input(path, std::ios::binary);
    if (!input) {
        throw std::runtime_error("unable to open INI file: " + path.string());
    }
    IniDocument document;
    std::string section;
    std::string line;
    bool first_line = true;
    while (std::getline(input, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (first_line && line.starts_with("\xEF\xBB\xBF")) {
            line.erase(0, 3);
        }
        first_line = false;
        line = trim(line);
        if (line.empty() || line.front() == ';' || line.front() == '#') {
            continue;
        }
        if (line.front() == '[' && line.back() == ']') {
            section = trim(line.substr(1, line.size() - 2));
            continue;
        }
        const auto equals = line.find('=');
        if (equals == std::string::npos) {
            continue;
        }
        auto key = trim(line.substr(0, equals));
        auto value = trim(line.substr(equals + 1));
        document.sections_[section][std::move(key)] = std::move(value);
    }
    return document;
}

std::optional<std::string> IniDocument::get(
    const std::string& section, const std::string& key) const {
    const auto section_it = sections_.find(section);
    if (section_it == sections_.end()) {
        return std::nullopt;
    }
    const auto key_it = section_it->second.find(key);
    return key_it == section_it->second.end()
        ? std::nullopt : std::optional<std::string>(key_it->second);
}

std::size_t IniDocument::section_count() const noexcept {
    return sections_.size();
}

std::size_t IniDocument::key_count() const noexcept {
    std::size_t count = 0;
    for (const auto& [name, section] : sections_) {
        static_cast<void>(name);
        count += section.size();
    }
    return count;
}

}  // namespace f1c::config
