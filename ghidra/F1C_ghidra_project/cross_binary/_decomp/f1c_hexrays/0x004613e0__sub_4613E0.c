// f1c  0x004613e0  size=88
int __thiscall sub_4613E0(_DWORD *this)
{
  int result; // eax
  int v3; // edi
  _DWORD *v4; // ebx
  _DWORD *v5; // [esp+8h] [ebp-4h]

  result = this[3973];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = this + 3869;
    v5 = this + 229;
    do
    {
      if ( !(unsigned __int8)sub_461530(2) )
        sub_462940(*v4);
      result = this[3973];
      ++v3;
      ++v4;
      v5 += 35;
    }
    while ( v3 < result );
  }
  return result;
}
