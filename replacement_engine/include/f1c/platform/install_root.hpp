#pragma once

#include <filesystem>

namespace f1c::platform {

std::filesystem::path resolve_install_root(
    const std::filesystem::path& executable_path,
    const std::filesystem::path& requested_root = {});

}  // namespace f1c::platform
