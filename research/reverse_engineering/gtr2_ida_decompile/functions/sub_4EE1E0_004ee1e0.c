int __thiscall sub_4EE1E0(int *this)
{
  int *v1; // esi
  int v2; // edi
  char *v4; // ebp
  const char *v5; // eax
  int v6; // eax
  int v7; // [esp+Ch] [ebp-128h]
  void *Block[2]; // [esp+10h] [ebp-124h] BYREF
  int v9; // [esp+18h] [ebp-11Ch]
  int v10; // [esp+1Ch] [ebp-118h]
  char v11; // [esp+20h] [ebp-114h]
  char Buffer[260]; // [esp+24h] [ebp-110h] BYREF
  int v13; // [esp+130h] [ebp-4h]

  v1 = this;
  memset(this, 0, 0x174u);
  v2 = dword_BE1D0C;
  if ( !dword_BE1D0C )
    return 1;
  Block[0] = 0;
  Block[1] = (void *)-1;
  sub_615860(WindowName);
  v9 = -1;
  v10 = -1;
  v11 = 0;
  v13 = 1;
  v4 = (char *)((char *)off_75B2C0 - (char *)v1);
  v7 = 93;
  do
  {
    v5 = (const char *)dword_91CA88;
    if ( !dword_91CA88 )
      v5 = WindowName;
    sprintf(Buffer, "%s%s", v5, *(const char **)&v4[(_DWORD)v1]);
    sub_615860(Buffer);
    v9 = -1;
    v10 = -1;
    v11 = 0;
    v6 = (*(int (__thiscall **)(int, void **, _DWORD, int))(*(_DWORD *)v2 + 92))(v2, Block, 0, 15);
    *v1 = v6;
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
    ++v1;
    --v7;
  }
  while ( v7 );
  if ( Block[0] )
    j_j__free(Block[0]);
  return 0;
}
