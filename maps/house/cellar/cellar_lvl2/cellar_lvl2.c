#include "cellar_lvl2.h"
#include "../../../../macros.h"

extern Variables bkg;

void init_cellar_lvl2()
{
    fadeout_black();
    HIDE_BKG;
    bkg.sliding = FALSE;
    bkg.camera_x = bkg.camera_y = 0;
    bkg.old_camera_x = bkg.camera_x;
    bkg.old_camera_y = bkg.camera_y;
    bkg.map_pos_x = (UBYTE)(bkg.camera_x >> 3u);
    bkg.map_pos_y = (UBYTE)(bkg.camera_y >> 3u);

    set_bkg_data_nonbanked(0, CELLAR_LVL2_TILE_COUNT, CELLAR_LVL2_TILE_DATA, BANK(CELLAR_LVL2_TILE_DATA));
    bkg.old_map_pos_x = bkg.old_map_pos_y = 255;
    bkg.camera_max_y = (CELLAR_LVL2_MAP_HEIGHT - 18) * 8;
    bkg.camera_max_x = (CELLAR_LVL2_MAP_WIDTH - 20) * 8;
    set_bkg_submap_nonbanked(bkg.map_pos_x, bkg.map_pos_y, 20, 18, CELLAR_LVL2_MAP_DATA, CELLAR_LVL2_MAP_WIDTH, BANK(CELLAR_LVL2_MAP_DATA));
    set_level(CELLAR_LVL2_MAP_WIDTH, CELLAR_LVL2_MAP_HEIGHT, CELLAR_LVL2_MAP_DATA, BANK(CELLAR_LVL2_MAP_DATA));

    bkg.old_camera_x = bkg.camera_x;
    bkg.old_camera_y = bkg.camera_y;

    bkg.redraw = FALSE;

    bkg.camera_style = horizontal_cam;

    SCX_REG = bkg.camera_x;
    SCY_REG = bkg.camera_y;
    SHOW_BKG;
    fadein_black();
}
