//
// Created by Alfie on 28/01/2025.
//

#ifndef SCENE_H
#define SCENE_H
#include <string>

class Scene {
public:
    /**
     * @param name String unique name - Keep them unique or the manager will not understand
     */
    explicit Scene(std::pmr::string& name);
    bool operator==(const Scene& second) const { return this->name == second.name; }

    virtual ~Scene() = default;

    virtual void on_first_load() = 0;
    virtual void update(float dt) = 0;

    [[nodiscard]] const std::pmr::string& get_name() const { return name; }

protected:
    /**
     * Unique String name ID
     */
    std::pmr::string name;
};

#endif //SCENE_H
