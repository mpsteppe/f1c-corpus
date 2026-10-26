_DWORD *__thiscall sub_406DE0(_DWORD *this, int a2)
{
  char *v3; // esi
  HANDLE v4; // eax
  char *v5; // esi
  int v7; // [esp+10h] [ebp-10h]
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+14h] [ebp-Ch] BYREF
  int v9; // [esp+24h] [ebp+4h]

  *this = &off_5D55B0;
  v3 = (char *)(this + 4);
  v7 = 3;
  do
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = -1;
    sub_578600(&byte_629120);
    *((_DWORD *)v3 + 2) = -1;
    *((_DWORD *)v3 + 3) = -1;
    v3[16] = 0;
    v3 += 20;
    --v7;
  }
  while ( v7 );
  this[20] = 0;
  *((_BYTE *)this + 88) = 0;
  this[21] = -1;
  sub_408FC0(this + 19);
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v4 = CreateMutexA(&MutexAttributes, 0, 0);
  this[20] = v4;
  if ( v4 )
    *((_BYTE *)this + 88) = 1;
  this[24] = 0;
  this[25] = -1;
  *this = &off_5D558C;
  this[1] = 1065353216;
  this[2] = a2;
  this[3] = 0;
  v5 = (char *)(this + 7);
  v9 = 3;
  do
  {
    sub_578600(&byte_629120);
    *((_DWORD *)v5 - 1) = -1;
    *(_DWORD *)v5 = -1;
    v5[4] = 0;
    v5 += 20;
    --v9;
  }
  while ( v9 );
  if ( *((_BYTE *)this + 88) )
    sub_4074A0(0);
  this[23] = -1;
  return this;
}
