int __thiscall sub_46BF10(_DWORD *this, char a2)
{
  float v3; // edi
  char v5; // [esp+7h] [ebp-369h] BYREF
  float v6; // [esp+8h] [ebp-368h]
  _BYTE v7[868]; // [esp+Ch] [ebp-364h] BYREF

  Delegation_e6f0(v7);
  v5 = 0;
  VirtualCallOnDAT008ac4c4_8d80(&byte_8AC494);
  if ( dword_7C56A4 > 0 )
  {
    if ( dword_7C56A4 <= 6 )
    {
      v6 = flt_8ACF94 - flt_8ACF90;
    }
    else if ( dword_7C56A4 == 7 )
    {
      v6 = 1000000000.0;
    }
  }
  sub_4988C0(0);
  v3 = v6;
  while ( (unsigned __int8)AIOvertake(&v5, LODWORD(v3)) )
  {
    if ( v5 )
      break;
    sub_4A1830(&unk_7CE2A4);
    if ( a2 )
    {
      sub_496880(this[16]);
      ShortComputation_7250(1);
      sub_496E90(1);
    }
  }
  if ( dword_7C56A4 == 7 )
  {
    if ( dword_5EB10C )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
    BufferInitWith10fDefaults(flt_5EA618);
    RaceCommentary();
  }
  sub_4988C0(1);
  ShortComputation_7250(1);
  return EmptyStub_0170(v7);
}
