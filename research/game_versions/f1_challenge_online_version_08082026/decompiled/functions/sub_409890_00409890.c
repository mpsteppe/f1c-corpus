int __thiscall sub_409890(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // ecx
  int v7; // [esp-4h] [ebp-Ch]

  if ( sub_545F40(dword_8AFE88) )
  {
    v3 = sub_547920(aMirrorBmp);
    v4 = v3;
    if ( v3 )
    {
      if ( (*(_DWORD *)(*(_DWORD *)(v3 + 84) + 24) & 0x40000) != 0 )
        this[2] = sub_544F50(aRearview);
      else
        this[2] = 0;
      if ( this[2] )
      {
        v7 = *(_DWORD *)(v4 + 84);
        this[3] = v7;
        sub_542560(v7);
        if ( sub_544F50(aMainview) )
          sub_542540(sub_409950, 0);
        sub_409970(this);
        v5 = this[3];
      }
      else
      {
        v5 = *(_DWORD *)(v4 + 84);
      }
      sub_543440(0, 0, *(_DWORD *)(v5 + 28), *(_DWORD *)(v5 + 32), &unk_686B75);
    }
  }
  return 0;
}
