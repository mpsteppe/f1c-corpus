void __stdcall sub_405E20(float *a1, char *String2)
{
  char *v2; // ebp
  int v3; // edi
  int v4; // ebx
  const char *v5; // eax
  int v6; // eax
  int v7; // ebx
  float *v8; // eax
  float v9; // ecx
  float v10; // edx
  float v11; // eax
  float *v12; // eax
  double v13; // st7
  double v14; // st6
  unsigned int v15; // kr00_4
  __int32 v16; // ebp
  char *v17; // [esp+0h] [ebp-2Ch] BYREF
  float v18; // [esp+14h] [ebp-18h]
  float v19; // [esp+18h] [ebp-14h]
  float v20; // [esp+1Ch] [ebp-10h]
  int v21[2]; // [esp+20h] [ebp-Ch] BYREF
  float v22; // [esp+28h] [ebp-4h]

  v2 = String2;
  v3 = 0;
  *(_DWORD *)String2 = 0;
  *((_DWORD *)String2 + 1) = 0;
  *((_DWORD *)String2 + 2) = 0;
  if ( *((int *)a1 + 6) > 0 )
  {
    do
    {
      v4 = *(_DWORD *)(*((_DWORD *)a1 + 8) + 4 * v3);
      v5 = *(const char **)(v4 + 4);
      v17 = v2;
      v15 = __readeflags();
      v16 = dword_16C6F3C + 1823753253;
      __writeeflags(v15);
      v2 = (char *)_InterlockedExchange((volatile __int32 *)&v17, v16);
      if ( !_stricmp(v5, v17) )
        break;
      ++v3;
    }
    while ( v3 < *((_DWORD *)a1 + 6) );
    if ( v3 != *((_DWORD *)a1 + 6) )
    {
      v6 = *(_DWORD *)(v4 + 48);
      v7 = v4 + 48;
      if ( v6 > 0 )
      {
        v8 = (float *)sub_4058B0(v7, v21, 0.0);
        v9 = v8[1];
        v18 = *v8;
        v10 = v8[2];
        v11 = a1[5];
        v19 = v9;
        v20 = v10;
        v12 = (float *)sub_4058B0(v7, v21, v11);
        v13 = *v12;
        v14 = v12[1];
        v22 = v12[2];
        *(float *)v2 = v13 - v18;
        *((float *)v2 + 1) = v14 - v19;
        *((float *)v2 + 2) = v22 - v20;
      }
    }
  }
}
