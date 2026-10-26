#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace f1c::bootstrap {

struct Options {
    std::filesystem::path executable_path;
    std::filesystem::path requested_root;
    bool inventory_only = false;
};

Options parse_options(const std::vector<std::wstring>& arguments,
                      const std::filesystem::path& executable_path);

class Application {
public:
    int run(const Options& options) const;
};

}  // namespace f1c::bootstrap
