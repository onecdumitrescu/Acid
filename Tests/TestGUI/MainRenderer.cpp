#include "MainRenderer.hpp"

#include <Scenes/Scenes.hpp>
#include <Renderer/Renderer.hpp>
#include <Guis/RendererGuis.hpp>
#include <Fonts/RendererFonts.hpp>

namespace test
{
	const RenderpassCreate RENDERPASS_0_CREATE = RenderpassCreate
	{
		0, 0, // width / height
		{
			Attachment(0, ATTACHMENT_DEPTH), // depth
			Attachment(1, ATTACHMENT_SWAPCHAIN) // swapchain
		}, // images
		{
			SubpassType(0, {1}),
		} // subpasses
	};

	MainRenderer::MainRenderer() :
		IManagerRender({RENDERPASS_0_CREATE})
	{
	}

	void MainRenderer::Start()
	{
		Renderer::Get()->AddRenderer<RendererGuis>(GraphicsStage(0, 0));
		Renderer::Get()->AddRenderer<RendererFonts>(GraphicsStage(0, 0));
	}

	void MainRenderer::Update()
	{
	}
}