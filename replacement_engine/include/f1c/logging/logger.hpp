#pragma once

#include <filesystem>
#include <fstream>
#include <mutex>
#include <string_view>

namespace f1c::logging {

class Logger {
public:
    explicit Logger(const std::filesystem::path& path);
    void info(std::string_view message);
    void error(std::string_view message);

private:
    void write(std::string_view level, std::string_view message);

    std::ofstream stream_;
    std::mutex mutex_;
};

}  // namespace f1c::logging
