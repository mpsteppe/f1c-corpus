// f1c  0x0055c3c0  size=126
int __thiscall sub_55C3C0(int *this, _DWORD *a2)
{
  int v3; // eax
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD v7[8]; // [esp+8h] [ebp-20h] BYREF

  v3 = a2[6];
  if ( (v3 & 1) != 0 )
  {
    v4 = (_DWORD *)a2[2];
  }
  else if ( (v3 & 2) != 0 )
  {
    v4 = (_DWORD *)a2[3];
  }
  else
  {
    v4 = a2;
  }
  v5 = (*(int (__stdcall **)(_DWORD *, _DWORD *))(*v4 + 32))(v4, v7);
  *this = v5;
  if ( v5 )
    return 255;
  if ( v7[0] == 22 )
    sub_55C450(21, 0, &a2);
  else
    sub_55C450(v7[0], 0, &a2);
  return (int)a2;
}
