/**********************************************************************************
// Platformer (C�digo Fonte)
//
// Cria��o:     05 Out 2011
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exemplo de jogo estilo platforma
//
**********************************************************************************/

#include "Engine.h"
#include "Platformer.h"
#include "Resources.h"

#include "Home.h"
// -----------------------------------------------------------------------------

Scene * Platformer::scene = nullptr;

// -----------------------------------------------------------------------------

void Platformer::Init()
{
}

// ------------------------------------------------------------------------------

void Platformer::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena do jogo
    scene->Update();
    scene->CollisionDetection();
} 

// ------------------------------------------------------------------------------

void Platformer::Draw()
{
    scene->Draw();
    scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void Platformer::Finalize()
{
    delete scene;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(600, 300);
    engine->window->Color(150, 200, 230);
    engine->window->Title("Platformer");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    int status = engine->Start(new Home());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

