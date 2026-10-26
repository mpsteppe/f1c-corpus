int __thiscall sub_460A60(_DWORD *this)
{
  int v2; // edi
  _DWORD *v3; // ebx
  int v4; // ebx
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // eax
  char *v8; // ebx
  int v9; // eax
  int v10; // edi
  int v12; // [esp+Ch] [ebp-154h]
  int v13; // [esp+Ch] [ebp-154h]
  _DWORD *v14; // [esp+10h] [ebp-150h] BYREF
  int v15; // [esp+14h] [ebp-14Ch]
  int *v16; // [esp+18h] [ebp-148h]
  _DWORD v17[52]; // [esp+1Ch] [ebp-144h] BYREF
  _BYTE v18[116]; // [esp+ECh] [ebp-74h] BYREF

  sub_4D1930(&dword_79FC40);
  while ( sub_4D18F0(v17) )
  {
    if ( (v17[0] & 0xC000000) != 0x4000000 )
    {
      if ( (unsigned __int8)sub_462B90(this) )
      {
        sub_46D020(v17);
      }
      else
      {
        v15 = sub_463B60(*this);
        v2 = 0;
        v12 = 0;
        if ( (int)this[1628] > 0 )
        {
          v3 = this + 188;
          v16 = this + 1580;
          v14 = this + 188;
          do
          {
            if ( v2 != v15
              && (this[1680] != 3 || (unsigned __int8)sub_462C60(1))
              && ((v17[0] & 0xC000000) == 0xC000000 || (unsigned __int8)sub_462C00(v3)) )
            {
              v4 = *v16;
              v5 = &this[29 * v15];
              if ( (unsigned __int8)sub_462C00(v5 + 188) && (v17[0] & 0x3Fu) < 0x30 )
                v17[0] = v17[0] & 0xFFFFFFC0 | *((char *)v5 + 852);
              sub_463A40(v17, 1, v4, 2000);
              v2 = v12;
              v3 = v14;
            }
            v6 = this[1628];
            ++v2;
            v3 += 29;
            v12 = v2;
            ++v16;
            v14 = v3;
          }
          while ( v2 < v6 );
        }
      }
    }
  }
  if ( (unsigned __int8)sub_462B90(this) )
  {
    v15 = sub_463B60(*this);
    sub_462BC0(v18);
    sub_463B50(*this);
    v7 = 0;
    v13 = 0;
    if ( (int)this[1628] > 0 )
    {
      v8 = (char *)(this + 213);
      do
      {
        if ( v7 != v15 && (this[1680] != 3 || (unsigned __int8)sub_462C60(1)) )
        {
          if ( (unsigned __int8)sub_462C00(v8 - 100) )
          {
            v9 = *v8;
            v10 = this[v9 + 1629];
            sub_46D190(v9, v10);
            while ( (unsigned __int8)sub_46D970(&v14) )
              sub_463A40(v14, 1, v10, 500);
          }
        }
        v7 = v13 + 1;
        v8 += 116;
        ++v13;
      }
      while ( v13 < this[1628] );
    }
    nullsub_6(v18);
  }
  return sub_56A460(0);
}
