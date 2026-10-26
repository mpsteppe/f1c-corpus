void __stdcall sub_562C80(float a1, char a2)
{
  char v2; // al
  int v3; // ebx
  unsigned int v4; // eax
  char *v5; // edi
  int v7; // esi
  int v8; // ecx
  int v9; // edi
  int v10; // [esp+10h] [ebp-38h]
  float v11; // [esp+10h] [ebp-38h]
  int v12; // [esp+14h] [ebp-34h] BYREF
  int v13; // [esp+18h] [ebp-30h]
  _BYTE v14[4]; // [esp+1Ch] [ebp-2Ch] BYREF
  char Buffer[7]; // [esp+20h] [ebp-28h] BYREF
  char v16; // [esp+27h] [ebp-21h] BYREF
  _BYTE v17[32]; // [esp+28h] [ebp-20h] BYREF

  v2 = byte_903B98;
  if ( !a2 )
    v2 = byte_903B99;
  v3 = 0;
  v17[0] = 0;
  if ( dword_903B9C > 0 )
  {
    v10 = v2;
    do
    {
      sprintf(Buffer, "%c", v3 + v10);
      v4 = strlen(Buffer) + 1;
      v5 = &v16;
      while ( *++v5 )
        ;
      qmemcpy(v5, Buffer, v4);
      ++v3;
    }
    while ( v3 < dword_903B9C );
  }
  if ( a1 <= 0.0 )
    a1 = 0.001;
  v7 = dword_FAE92C;
  if ( dword_FAE92C )
  {
    v11 = *(float *)(dword_FAE92C + 156);
    v8 = dword_FAE92C;
    v13 = *(_DWORD *)(dword_FAE92C + 152);
    *(float *)(dword_FAE92C + 156) = v11 * a1;
    ((void (__thiscall *)(int, char *))loc_5F0350)(v8, byte_FFFFFF);
    v9 = 640;
    if ( dword_FAE92C )
    {
      sub_5F0380(v17, &v12, v14, 64);
      v9 = 640 - v12 / 2;
    }
    sub_5F0DD0(v17, v9, (unsigned __int64)(206.0 / a1), dword_FB2790, 0);
    *(_DWORD *)(v7 + 152) = v13;
    *(float *)(v7 + 156) = v11;
  }
}
