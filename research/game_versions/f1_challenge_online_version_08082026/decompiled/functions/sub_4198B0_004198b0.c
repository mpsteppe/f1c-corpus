void __thiscall sub_4198B0(_DWORD *this, _DWORD *a2)
{
  int v3; // ebp
  int v4; // edi
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  float v9[8]; // [esp+10h] [ebp-20h] BYREF

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 )
    {
      v3 = this[a2[4645] + 108];
      v4 = a2[4120];
      if ( v3 != v4 && dword_7C56A4 == 5 )
      {
        sub_4144D0(v9);
        this[a2[4645] + 108] = v4;
        v5 = a2[4645];
        if ( *(_DWORD *)(dword_7C54E8 + 18580) == v5 )
        {
          if ( a2[4111] == 1 )
            return;
          if ( v4 >= v3 )
          {
            if ( v4 == 1 )
              return;
            v6 = 18;
          }
          else
          {
            v6 = 17;
          }
          sub_4144F0(v9, v6, v4, -1, -1, -1, -2.0, -2.0);
          goto LABEL_19;
        }
        if ( v4 != 1 )
        {
          v7 = a2[4111];
          if ( v7 != 1 )
          {
            if ( v7 == 2 )
              v8 = 7;
            else
              v8 = (v4 >= v3) + 8;
            sub_4144F0(v9, v8, a2[4647], this[v5 + 108], -1, -1, -2.0, -2.0);
LABEL_19:
            sub_418560(flt_5EA618, v9);
          }
        }
      }
    }
  }
}
