#include <3ds.h>
#include "ui.h"
#include "video.h"
#include "network.h"

int main() {
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL);
    videoInit();
    networkInit();

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();

        // 下画面UI更新（検索・リスト操作）
        updateUI();

        // 上画面動画再生
        updateVideo();

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();

        if (kDown & KEY_START) break; // STARTで終了
    }

    networkExit();
    videoExit();
    gfxExit();
    return 0;
}
