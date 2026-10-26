#pragma once

#include <filesystem>
#include <map>
#include <optional>
#include <string>

namespace f1c::config {

class IniDocument {
public:
    static IniDocument load(const std::filesystem::path& path);

    [[nodiscard]] std::optional<std::string> get(
        const std::string& section, const std::string& key) const;
    [[nodiscard]] std::size_t section_count() const noexcept;
    [[nodiscard]] std::size_t key_count() const noexcept;

private:
    using Section = std::map<std::string, std::string, std::less<>>;
    std::map<std::string, Section, std::less<>> sections_;
};

}  // namespace f1c::config
