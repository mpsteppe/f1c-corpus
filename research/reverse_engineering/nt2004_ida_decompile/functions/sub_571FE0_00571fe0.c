_DWORD *__thiscall sub_571FE0(_DWORD *this)
{
  _DWORD *v2; // edi
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  int i; // edi
  HANDLE v6; // eax
  bool v7; // zf
  _DWORD *result; // eax
  _DWORD *v9; // [esp+10h] [ebp-28h]
  _DWORD *v10; // [esp+10h] [ebp-28h]
  struct _SECURITY_ATTRIBUTES MutexAttributes; // [esp+20h] [ebp-18h] BYREF
  int v12; // [esp+34h] [ebp-4h]

  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  v12 = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  v2 = operator new(4u);
  LOBYTE(v12) = 2;
  if ( v2 )
  {
    v3 = operator new(0x9084u);
    LOBYTE(v12) = 3;
    if ( v3 )
    {
      *v3 = 2;
      v9 = v3 + 1;
      `eh vector constructor iterator'(v3 + 1, 0x4840u, 2, sub_572120, (void (__thiscall *)(void *))nullsub_5);
      v4 = v9;
      v10 = v2;
      *v2 = v4;
    }
    else
    {
      v10 = v2;
      *v2 = 0;
    }
  }
  else
  {
    v10 = 0;
  }
  LOBYTE(v12) = 1;
  sub_5735F0(v10, 1);
  for ( i = 0; i < 36992; i += 18496 )
    sub_5765C0(i + *v10, 0);
  this[8] = 0;
  *((_BYTE *)this + 40) = 0;
  this[9] = -1;
  MutexAttributes.nLength = 12;
  MutexAttributes.lpSecurityDescriptor = 0;
  MutexAttributes.bInheritHandle = 1;
  v6 = CreateMutexA(&MutexAttributes, 0, 0);
  this[8] = v6;
  v7 = v6 == 0;
  result = this;
  if ( !v7 )
    *((_BYTE *)this + 40) = 1;
  return result;
}
