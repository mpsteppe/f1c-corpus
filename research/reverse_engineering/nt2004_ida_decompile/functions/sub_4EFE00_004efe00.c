void sub_4EFE00()
{
  const char *v0; // eax
  _DWORD v1[2]; // [esp+10h] [ebp-214h] BYREF
  int v2; // [esp+18h] [ebp-20Ch]
  int v3; // [esp+1Ch] [ebp-208h]
  char v4; // [esp+20h] [ebp-204h]
  char Buffer[509]; // [esp+24h] [ebp-200h] BYREF
  __int16 v6; // [esp+221h] [ebp-3h]
  char v7; // [esp+223h] [ebp-1h]

  if ( dword_7D6BB8 && !(*(int (__thiscall **)(int))(*(_DWORD *)dword_7D6BB8 + 8))(dword_7D6BB8) )
  {
    v1[0] = 0;
    v1[1] = -1;
    sub_578600(&byte_629120);
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x1FCu);
    v6 = 0;
    v7 = 0;
    v0 = *(const char **)dword_62A070;
    v2 = -1;
    v3 = -1;
    v4 = 0;
    if ( !*(_DWORD *)dword_62A070 )
      v0 = &byte_629120;
    sprintf(Buffer, "%s%s", v0, aPitPitsoundsMp);
    sub_578600(Buffer);
    v2 = -1;
    v3 = -1;
    v4 = 0;
    (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)dword_7D6BB8 + 4))(dword_7D6BB8, v1, 1, 0);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_7D6BB8 + 32))(dword_7D6BB8, LODWORD(flt_767898));
    if ( v1[0] )
      sub_5BE8AE();
  }
}
