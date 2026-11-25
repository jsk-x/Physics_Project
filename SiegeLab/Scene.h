#pragma once
#include <array>
#include <utility>

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
    public:
        EntityId create(T value) {
            for (int i = 0; i < Capacity; ++i) {
                if (!slots_[i].alive) {
                    slots_[i].value = std::move(value);
                    slots_[i].alive = true;
                    return EntityId{ i, slots_[i].generation };
                }
            }
            return kInvalidEntityId;
        }

        T* get(EntityId id) {
            if (!isAlive(id)) {
                return nullptr;
            }
            return &slots_[id.slot].value;
        }

        bool destroy(EntityId id) {
            if (!isAlive(id)) {
                return false;
            }

            reset(slots_[id.slot]);
            return true;
        }

        using Callback = void (*)(T&);

        void forEach(Callback func) {
            for (Slot& slot : slots_) {
                if (slot.alive) {
                    func(slot.value);
                }
            }
        }

        void clear() {
            for (Slot& slot : slots_) {
                if (slot.alive) {
                    reset(slot);
                }
            }
        }

    private:
        struct Slot {
            T value{};
            unsigned int generation = 0;
            bool alive = false;
        };

        bool isAlive(EntityId id) const {
            if (id.slot < 0 || id.slot >= Capacity) {
                return false;
            }
            return slots_[id.slot].alive &&
                slots_[id.slot].generation == id.generation;
        }

        void reset(Slot& slot) {
            slot.value = T();
            slot.alive = false;
            ++slot.generation;
        }
        std::array<Slot, Capacity> slots_;
    };

}