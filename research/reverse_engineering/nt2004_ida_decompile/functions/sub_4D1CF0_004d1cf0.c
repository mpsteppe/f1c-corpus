int __stdcall sub_4D1CF0(int a1, int a2)
{
  int result; // eax
  int v3; // ecx
  int v4; // ecx
  int v5; // edx
  _WORD *v6; // ecx
  int v7; // esi
  _WORD *v8; // ecx
  int v9; // esi
  _WORD *v10; // ecx
  int v11; // esi
  _WORD *v12; // ecx
  int v13; // esi
  _WORD *v14; // ecx
  int v15; // edi
  _WORD *v16; // esi
  int v17; // edi
  _WORD *v18; // esi
  int v19; // edi
  _WORD *v20; // esi
  int v21; // edi
  _WORD *v22; // esi
  int v23; // [esp+Ch] [ebp+4h]
  int v24; // [esp+Ch] [ebp+4h]
  int v25; // [esp+Ch] [ebp+4h]
  int v26; // [esp+Ch] [ebp+4h]

  result = a1;
  switch ( a1 )
  {
    case 0:
      result = a2 + 512;
      v3 = 256;
      do
      {
        *(_WORD *)(result + 512) = 0;
        *(_WORD *)result = 0;
        *(_WORD *)(result - 512) = 0;
        result += 2;
        --v3;
      }
      while ( v3 );
      break;
    case 1:
      result = a2 + 512;
      v4 = 256;
      do
      {
        *(_WORD *)(result + 512) = -5536;
        *(_WORD *)result = -5536;
        *(_WORD *)(result - 512) = -5536;
        result += 2;
        --v4;
      }
      while ( v4 );
      break;
    case 2:
      v5 = 0;
      v6 = (_WORD *)(a2 + 512);
      do
      {
        result = v5;
        v6[256] = v5;
        *v6 = v5;
        *(v6 - 256) = v5;
        v5 += 256;
        ++v6;
      }
      while ( v5 < 0x10000 );
      break;
    case 3:
      v7 = 0;
      v8 = (_WORD *)(a2 + 512);
      do
      {
        result = (v7 / 128) << 15;
        if ( result > 0xFFFF )
          result = 0xFFFF;
        v8[256] = result;
        *v8 = result;
        *(v8 - 256) = result;
        ++v7;
        ++v8;
      }
      while ( v7 < 256 );
      break;
    case 4:
      v9 = 0;
      v10 = (_WORD *)(a2 + 512);
      do
      {
        result = (v9 / 64) << 14;
        if ( result > 0xFFFF )
          result = 0xFFFF;
        v10[256] = result;
        *v10 = result;
        *(v10 - 256) = result;
        ++v9;
        ++v10;
      }
      while ( v9 < 256 );
      break;
    case 5:
      v11 = 0;
      v12 = (_WORD *)(a2 + 512);
      do
      {
        result = (v11 / 32) << 13;
        if ( result > 0xFFFF )
          result = 0xFFFF;
        v12[256] = result;
        *v12 = result;
        *(v12 - 256) = result;
        ++v11;
        ++v12;
      }
      while ( v11 < 256 );
      break;
    case 6:
      v13 = 0;
      v14 = (_WORD *)(a2 + 512);
      do
      {
        result = (v13 / 16) << 12;
        if ( result > 0xFFFF )
          result = 0xFFFF;
        v14[256] = result;
        *v14 = result;
        *(v14 - 256) = result;
        ++v13;
        ++v14;
      }
      while ( v13 < 256 );
      break;
    case 7:
      v15 = 0;
      v23 = 0;
      v16 = (_WORD *)(a2 + 512);
      do
      {
        result = (unsigned int)(__int64)(pow((double)v23 * 0.00390625, 0.3635999858379364) * 256.0) << 8;
        if ( result > 0xFFFF )
          result = 0xFFFF;
        ++v15;
        v16[256] = result;
        *v16 = result;
        *(v16 - 256) = result;
        ++v16;
        v23 = v15;
      }
      while ( v15 < 256 );
      break;
    case 8:
      v17 = 0;
      v24 = 0;
      v18 = (_WORD *)(a2 + 512);
      do
      {
        result = (unsigned int)(__int64)(pow((double)v24 * 0.00390625, 0.3030000030994415) * 256.0) << 8;
        if ( result > 0xFFFF )
          result = 0xFFFF;
        ++v17;
        v18[256] = result;
        *v18 = result;
        *(v18 - 256) = result;
        ++v18;
        v24 = v17;
      }
      while ( v17 < 256 );
      break;
    case 9:
      v19 = 0;
      v25 = 0;
      v20 = (_WORD *)(a2 + 512);
      do
      {
        result = (unsigned int)(__int64)(pow((double)v25 * 0.00390625, 0.2597000002861023) * 256.0) << 8;
        if ( result > 0xFFFF )
          result = 0xFFFF;
        ++v19;
        v20[256] = result;
        *v20 = result;
        *(v20 - 256) = result;
        ++v20;
        v25 = v19;
      }
      while ( v19 < 256 );
      break;
    case 10:
      v21 = 0;
      v26 = 0;
      v22 = (_WORD *)(a2 + 512);
      do
      {
        result = (unsigned int)(__int64)(pow((double)v26 * 0.00390625, 0.2272000014781952) * 256.0) << 8;
        if ( result > 0xFFFF )
          result = 0xFFFF;
        ++v21;
        v22[256] = result;
        *v22 = result;
        *(v22 - 256) = result;
        ++v22;
        v26 = v21;
      }
      while ( v21 < 256 );
      break;
    default:
      return result;
  }
  return result;
}
