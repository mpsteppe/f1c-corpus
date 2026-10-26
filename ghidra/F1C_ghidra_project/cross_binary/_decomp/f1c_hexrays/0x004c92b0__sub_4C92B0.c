// f1c  0x004c92b0  size=81
int *__thiscall sub_4C92B0(_DWORD *this, int a2, int a3)
{
  int *result; // eax
  int v4; // ecx
  int v5; // edx
  _DWORD v6[3]; // [esp+0h] [ebp-Ch] BYREF

  this[7] = a2;
  result = (int *)sub_4C9260(this);
  if ( result )
  {
    v5 = *result;
    memset(v6, 0, sizeof(v6));
    return (int *)(*(int (__thiscall **)(int *, int, int, _DWORD *, int, int, int))(v5 + 4))(
                    result,
                    2,
                    v4 + 8,
                    v6,
                    a3,
                    1065353216,
                    1);
  }
  return result;
}
