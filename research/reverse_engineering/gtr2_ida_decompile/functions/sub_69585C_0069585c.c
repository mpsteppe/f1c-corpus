int __thiscall sub_69585C(_DWORD *this, int a2)
{
  int i; // eax
  int v3; // edx

  for ( i = this[4]; ; i = *(_DWORD *)(i + 32) )
  {
    if ( !i )
      return a2;
    v3 = *(_DWORD *)(i + 16);
    if ( v3 == 2 || v3 == 3 || v3 == 4 )
      break;
  }
  sub_694B97((int)this, (int)(this + 8), 3064, "object literals are not allowed inside functions");
  return 0;
}
