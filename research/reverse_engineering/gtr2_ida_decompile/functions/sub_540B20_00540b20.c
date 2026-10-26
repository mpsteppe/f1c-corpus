void sub_540B20()
{
  const CHAR *v0; // eax
  const CHAR *v1; // eax
  float v2; // [esp+Ch] [ebp-22Ch]
  void *Block[4]; // [esp+14h] [ebp-224h] BYREF
  char v4; // [esp+24h] [ebp-214h]
  char Buffer[509]; // [esp+28h] [ebp-210h] BYREF
  __int16 v6; // [esp+225h] [ebp-13h]
  char v7; // [esp+227h] [ebp-11h]
  int v8; // [esp+234h] [ebp-4h]

  if ( dword_BE1D14 && !(*(int (__thiscall **)(int))(*(_DWORD *)dword_BE1D14 + 8))(dword_BE1D14) )
  {
    sub_40B430();
    memset(Buffer, 0, sizeof(Buffer));
    v6 = 0;
    v7 = 0;
    v8 = 0;
    if ( *(_DWORD *)dword_B640C8 || !dword_B71F00 )
    {
      v1 = (const CHAR *)dword_91CA88;
      if ( !dword_91CA88 )
        v1 = WindowName;
      sprintf(Buffer, "%s%s", v1, "Pit\\pitSounds.mp3");
    }
    else
    {
      v0 = (const CHAR *)dword_91CA88;
      if ( !dword_91CA88 )
        v0 = WindowName;
      sprintf(Buffer, "%s%s", v0, "Pit\\pitSoundsPrivate.mp3");
    }
    sub_615860(Buffer);
    Block[2] = (void *)-1;
    Block[3] = (void *)-1;
    v4 = 0;
    (*(void (__thiscall **)(int, void **, int, _DWORD))(*(_DWORD *)dword_BE1D14 + 4))(dword_BE1D14, Block, 1, 0);
    v2 = *(float *)&dword_B70948 * flt_B70A20;
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_BE1D14 + 28))(LODWORD(v2));
    if ( Block[0] )
      j_j__free(Block[0]);
  }
}
