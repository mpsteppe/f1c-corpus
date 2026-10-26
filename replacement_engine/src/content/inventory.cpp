#include "f1c/content/inventory.hpp"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace f1c::content {

Inventory scan_installation(const std::filesystem::path& root) {
    Inventory result;
    std::error_code error;
    const std::filesystem::recursive_directory_iterator end;
    for (std::filesystem::recursive_directory_iterator iterator(
             root, std::filesystem::directory_options::skip_permission_denied, error);
         iterator != end; iterator.increment(error)) {
        if (error) {
            error.clear();
            continue;
        }
        if (!iterator->is_regular_file(error)) {
            error.clear();
            continue;
        }
        ++result.files;
        result.bytes += iterator->file_size(error);
        error.clear();
        auto extension = iterator->path().extension().string();
        std::transform(extension.begin(), extension.end(), extension.begin(),
                       [](unsigned char character) {
                           return static_cast<char>(std::tolower(character));
                       });
        if (extension.empty()) {
            extension = "<none>";
        }
        ++result.extensions[extension];
    }
    return result;
}

std::string render_inventory(const Inventory& inventory) {
    std::ostringstream output;
    output << "content inventory: " << inventory.files << " files, "
           << inventory.bytes << " bytes, " << inventory.extensions.size()
           << " extension groups";
    return output.str();
}

}  // namespace f1c::content
