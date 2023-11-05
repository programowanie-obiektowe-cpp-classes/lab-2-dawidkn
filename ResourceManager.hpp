#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : resource_(std::make_unique<Resource>()) {}

    double get() const { return resource_->get(); }

    ResourceManager(const ResourceManager& other) : resource_(std::make_unique<Resource>(*other.resource_)) {}

    ResourceManager(ResourceManager&& other) noexcept : resource_(std::move(other.resource_)) {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource_ = std::make_unique<Resource>(*other.resource_);
        }
        return *this;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            resource_ = std::move(other.resource_);
        }
        return *this;
    }

private:
    std::unique_ptr<Resource> resource_;
};

