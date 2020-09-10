#include "zint.h"
#include <lua.h>
#include <lauxlib.h>
#include <string.h>

static int
lencode(lua_State *L) {
    struct zint_symbol *pMySymbol = NULL;
    pMySymbol = ZBarcode_Create();
    if(pMySymbol != NULL){
        uint8_t *buffer = luaL_checkstring(L, 1);
        char *filename = luaL_checkstring(L, 2);
        int scale = luaL_checkinteger(L, 3);
        strcpy(pMySymbol->outfile, filename);
        pMySymbol->symbology = BARCODE_QRCODE;
        pMySymbol->scale = scale;
        int err = ZBarcode_Encode_and_Print(pMySymbol, buffer, 0, 0);
        if(err == 0){
            lua_pushlstring(L, "ok", 2);
        }
        ZBarcode_Delete(pMySymbol);
    }else{

    }
	return 1;
}

int
luaopen_zint(lua_State *L) {
	luaL_Reg l[] = {
		{ "encode", lencode },
		{ NULL, NULL },
	};
	luaL_newlib(L,l);
	return 1;
}