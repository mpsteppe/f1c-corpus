void __thiscall sub_5D60A0(void **this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // [esp+0h] [ebp-8h]

  v2 = 0;
  if ( (int)*this > 0 )
  {
    v3 = 0;
    do
    {
      sub_5C4E20();
      ++v2;
      v3 += 32;
    }
    while ( v2 < (int)*this );
  }
  sub_4F14D0(v4);
  sub_5A8D10(this[2]);
}
