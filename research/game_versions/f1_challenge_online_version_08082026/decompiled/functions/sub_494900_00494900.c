int sub_494900()
{
  void *v0; // esi
  void *v1; // esi
  int result; // eax
  void *v3; // esi
  void *v4; // esi

  if ( dword_7CDE0C )
  {
    sub_5539F0(dword_7CDE0C);
    dword_7CDE0C = 0;
  }
  if ( dword_7CDE04 )
  {
    sub_5502C0();
    v0 = (void *)dword_7CDE04;
    if ( dword_7CDE04 )
    {
      j_nullsub_3(dword_7CDE04);
      sub_587BCF(v0);
    }
    dword_7CDE04 = 0;
    dword_7CDE08 = 0;
  }
  if ( dword_7CDE18 )
  {
    sub_5539F0(dword_7CDE18);
    dword_7CDE18 = 0;
  }
  if ( dword_7CDE10 )
  {
    sub_5502C0();
    v1 = (void *)dword_7CDE10;
    if ( dword_7CDE10 )
    {
      j_nullsub_3(dword_7CDE10);
      sub_587BCF(v1);
    }
    dword_7CDE10 = 0;
    dword_7CDE14 = 0;
  }
  result = dword_7CDE24;
  if ( dword_7CDE24 )
  {
    result = sub_5539F0(dword_7CDE24);
    dword_7CDE24 = 0;
  }
  if ( dword_7CDE1C )
  {
    result = sub_5502C0();
    v3 = (void *)dword_7CDE1C;
    if ( dword_7CDE1C )
    {
      j_nullsub_3(dword_7CDE1C);
      result = sub_587BCF(v3);
    }
    dword_7CDE1C = 0;
    dword_7CDE20 = 0;
  }
  if ( dword_7CDE28 )
  {
    result = sub_5502C0();
    v4 = (void *)dword_7CDE28;
    if ( dword_7CDE28 )
    {
      j_nullsub_3(dword_7CDE28);
      result = sub_587BCF(v4);
    }
    dword_7CDE28 = 0;
    dword_7CDE2C = 0;
  }
  return result;
}
