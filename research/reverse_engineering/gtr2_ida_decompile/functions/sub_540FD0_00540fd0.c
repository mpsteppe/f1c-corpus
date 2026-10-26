void __userpurge sub_540FD0(unsigned int a1, int a2, int a3)
{
  const char *v3; // eax
  void *Block[5]; // [esp+10h] [ebp-124h] BYREF
  char v5; // [esp+24h] [ebp-110h]
  char Buffer[256]; // [esp+28h] [ebp-10Ch] BYREF
  _UNKNOWN *retaddr; // [esp+134h] [ebp+0h]

  if ( !dword_BE1D0C )
  {
LABEL_4:
    if ( !dword_BE1D1C )
      return;
    goto LABEL_5;
  }
  if ( !dword_BE1D1C )
  {
    dword_BE1D1C = (*(int (**)(void))(*(_DWORD *)dword_BE1D0C + 96))();
    goto LABEL_4;
  }
LABEL_5:
  if ( a1 < 8 )
  {
    sub_40B430();
    v3 = (const char *)dword_91CA88;
    retaddr = 0;
    if ( !dword_91CA88 )
      v3 = WindowName;
    sprintf(Buffer, "%s%s", v3, off_903958[a1]);
    sub_615860(Buffer);
    Block[3] = (void *)-1;
    Block[4] = (void *)-1;
    v5 = 0;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_BE1D1C + 28))(dword_BE1D1C, a3);
    (*(void (__thiscall **)(int, void **, int, _DWORD))(*(_DWORD *)dword_BE1D1C + 4))(dword_BE1D1C, Block, 1, 0);
    if ( Block[0] )
      j_j__free(Block[0]);
  }
}
