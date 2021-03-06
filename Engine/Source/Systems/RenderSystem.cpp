#include "JemPCH.h"
#include "RenderSystem.h"

#include <ECS/ECSManager.h>
#include <ECS/Entity.h>
#include <Components/TextureComponent.h>
#include <Components/TransformComponent.h>
#include <Renderer/Renderer.h>

namespace Jem {

// ==================
// Jem::RenderSystem
// ==================
void RenderSystem(ECSManager* world) {
    for (Entity entity : world->GetEntitiesWith<TextureComponent, TransformComponent>()) {
        TextureComponent& sprite = world->GetComponent<TextureComponent>(entity);
        TransformComponent& transform = world->GetComponent<TransformComponent>(entity);
        
        Renderer::DrawTexturedRectangle(
            transform.position,
            transform.scale,
            sprite.texture,
            sprite.drawRegion,
            sprite.clipRegion,
            transform.rotation,
            sprite.isFlippedHorizontal,
            sprite.isFlippedVertical
        );
    }
}

}