int __thiscall sub_421380(void *this)
{
  int v1; // ebx
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // [esp+8h] [ebp-54h]
  _BYTE v11[80]; // [esp+Ch] [ebp-50h] BYREF

  v1 = 0;
  v10 = 0;
  if ( !this )
    return 0;
  v4 = sub_4C2850(&unk_7D2DB0);
  if ( sub_4C1370(v4) > 0 )
  {
    do
    {
      sub_4C2850(&unk_7D2DB0);
      sub_4C13A0(v1);
      sub_4C0A20(v11, 80);
      if ( sub_566810(v11, this) )
      {
        v5 = 0;
        v6 = sub_4C2850(&unk_7D2DB0);
        if ( sub_4C11D0(v6) > 0 )
        {
          v7 = 216;
          do
          {
            sub_4C2850(&unk_7D2DB0);
            if ( *(_DWORD *)(v7 + sub_4C13A0(v1)) == 10 )
              ++v10;
            ++v5;
            v7 += 4;
            v8 = sub_4C2850(&unk_7D2DB0);
          }
          while ( v5 < sub_4C11D0(v8) );
        }
      }
      ++v1;
      v9 = sub_4C2850(&unk_7D2DB0);
    }
    while ( v1 < sub_4C1370(v9) );
  }
  return v10;
}
