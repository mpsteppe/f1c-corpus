int __thiscall sub_4BE8C0(_DWORD *this, int a2, char *FileName)
{
  const char *v4; // ecx
  const char *v5; // eax
  const char *v6; // ecx
  const char *v7; // eax
  int v8; // esi
  int result; // eax
  int v10; // [esp+Ch] [ebp-110h] BYREF
  int v11; // [esp+10h] [ebp-10Ch] BYREF
  int v12; // [esp+14h] [ebp-108h] BYREF
  int v13; // [esp+18h] [ebp-104h] BYREF
  char Buffer[253]; // [esp+1Ch] [ebp-100h] BYREF
  __int16 v15; // [esp+119h] [ebp-3h]
  char v16; // [esp+11Bh] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v15 = 0;
  v16 = 0;
  v11 = 0;
  v13 = 0;
  v10 = 0;
  v12 = 0;
  sub_5924D0(dword_7DA988, (int)&v11, (int)aPitsMas);
  sub_5924D0(dword_7DA988, (int)&v13, (int)aPitanimsMas);
  v4 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v4 = &byte_629120;
  v5 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v5 = &byte_629120;
  sprintf(Buffer, "%s%s%s", v5, v4, aCdbMas);
  sub_5924D0(dword_7DA988, (int)&v10, (int)Buffer);
  v6 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v6 = &byte_629120;
  v7 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v7 = &byte_629120;
  sprintf(Buffer, "%s%s%s", v7, v6, aCmapsMas);
  sub_5924D0(dword_7DA988, (int)&v12, (int)Buffer);
  v8 = sub_4BD350(this, a2, FileName);
  if ( v11 )
    sub_592750(v11);
  if ( v13 )
    sub_592750(v13);
  if ( v10 )
    sub_592750(v10);
  if ( v12 )
    sub_592750(v12);
  result = v8;
  this[50] = -1;
  return result;
}
