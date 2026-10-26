#pragma once

#include <cstdint>
#include <filesystem>
#include <map>
#include <string>

namespace f1c::content {

struct Inventory {
    std::uint64_t files = 0;
    std::uint64_t bytes = 0;
    std::map<std::string, std::uint64_t, std::less<>> extensions;
};

Inventory scan_installation(const std::filesystem::path& root);
std::string render_inventory(const Inventory& inventory);

}  // namespace f1c::content
