int *__stdcall sub_6D8160(int a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // edx
  int v4; // edi
  int v5; // esi
  int v6; // ecx
  int *result; // eax
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  char *v10; // [esp+14h] [ebp-4h]
  int v11; // [esp+20h] [ebp+8h]

  v1 = *(_DWORD *)(a1 + 360);
  v2 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 0x2000);
  v3 = 0;
  *(_DWORD *)(v1 + 8) = v2;
  v4 = 0;
  v5 = 0;
  v8 = 0;
  v9 = 0;
  v11 = 0;
  v10 = (char *)&unk_807FFF;
  v6 = 0x8000;
  result = (int *)(v2 + 2048);
  do
  {
    result[512] = v11;
    result[768] = (int)v10;
    result[1024] = v9;
    result[1280] = v8;
    v11 -= 21709;
    v10 += 0x8000;
    v9 -= 27439;
    *result = v6;
    *(result - 512) = v3;
    *(result - 256) = v5;
    result[256] = v4;
    v6 += 7471;
    v3 += 19595;
    ++result;
    v5 += 38470;
    v4 -= 11059;
    v8 -= 5329;
  }
  while ( v6 <= 1937873 );
  return result;
}
