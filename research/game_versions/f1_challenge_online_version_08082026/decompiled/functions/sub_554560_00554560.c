int __thiscall sub_554560(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // edx
  int v5; // ecx

  if ( a2 == -1 || a2 == this[13] )
    return result;
  if ( !a2 )
  {
    result = (*(int (__stdcall **)(int, _DWORD, int, _DWORD))(*(_DWORD *)dword_8B89A0 + 252))(
               dword_8B89A0,
               *this,
               18,
               0);
    goto LABEL_10;
  }
  result = a2 - 1;
  if ( a2 != 1 )
  {
LABEL_10:
    this[13] = a2;
    return result;
  }
  v4 = *this;
  v5 = *(_DWORD *)dword_8B89A0;
  if ( (byte_8B8C48 & 1) != 0 )
    result = (*(int (__stdcall **)(int, int, int, int))(v5 + 252))(dword_8B89A0, v4, 18, 2);
  else
    result = (*(int (__stdcall **)(int, int, int, int))(v5 + 252))(dword_8B89A0, v4, 18, 1);
  this[13] = 1;
  return result;
}
