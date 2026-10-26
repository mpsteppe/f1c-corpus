#include "f1c/platform/install_root.hpp"

#include <stdexcept>

namespace f1c::platform {

std::filesystem::path resolve_install_root(
    const std::filesystem::path& executable_path,
    const std::filesystem::path& requested_root) {
    std::error_code error;
    auto root = requested_root.empty() ? executable_path.parent_path() : requested_root;
    root = std::filesystem::weakly_canonical(root, error);
    if (error || root.empty() || !std::filesystem::is_directory(root)) {
        throw std::runtime_error("installation root is not a readable directory");
    }
    return root;
}

}  // namespace f1c::platform
