#pragma once

namespace game {

    struct EntityId {
        int slot = -1;
        unsigned int generation = 0;
    };

    inline constexpr EntityId kInvalidEntityId{};

    class GameEntity {
    public:
        virtual ~GameEntity() = default;

        virtual void draw() = 0;

        virtual void unregisterColliders() {}
    };

    template <typename T, int Capacity>
    class ObjectPool {
        create();
        getId();
        destroy();
        clear();
    };

    struct SceneObjects {
        void createEntity();
        void getId();
        void flushRemovals();
    };

}