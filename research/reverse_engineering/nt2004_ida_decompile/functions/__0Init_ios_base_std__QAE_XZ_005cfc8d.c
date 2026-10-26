std::ios_base::Init *__thiscall std::ios_base::Init::Init(std::ios_base::Init *this)
{
  char v1; // bl
  int *v4; // [esp+Ch] [ebp-10h] BYREF
  int v5; // [esp+18h] [ebp-4h]

  v4 = 0;
  std::_Lockit::_Lockit((std::_Lockit *)&v4);
  if ( dword_628B94 < 0 )
  {
    dword_628B94 = 1;
    v1 = 1;
  }
  else
  {
    ++dword_628B94;
    v1 = 0;
  }
  std::_Lockit::~_Lockit((std::_Lockit *)&v4);
  if ( v1 )
  {
    v4 = (int *)&unk_7FF620;
    v5 = 0;
    if ( &unk_7FF620 )
      sub_5D0034(&off_6253F8);
    v4 = (int *)&unk_7FF4F8;
    v5 = 1;
    if ( &unk_7FF4F8 )
      sub_5D0034(&File);
    v4 = &dword_7FF5E0;
    v5 = 2;
    if ( &dword_7FF5E0 )
      sub_5CFF6D(&unk_7FF620, 1, 1);
    v4 = (int *)&unk_7FF550;
    v5 = 3;
    if ( &unk_7FF550 )
      sub_5CFE4F(&unk_7FF4F8, 1, 1, 1);
    v4 = (int *)&unk_7FF588;
    *(int *)((char *)&dword_7FF5E0 + *(_DWORD *)(dword_7FF5E0 + 4) + 44) = (int)&unk_7FF550;
    v5 = 4;
    if ( &unk_7FF588 )
      sub_5D0034(&unk_625438);
    v4 = dword_7FF678;
    v5 = 5;
    if ( dword_7FF678 )
      sub_5CFE4F(&unk_7FF588, 1, 1, 1);
    v4 = dword_7FF4C0;
    *(int *)((char *)&dword_7FF678[11] + *(_DWORD *)(dword_7FF678[0] + 4)) = (int)&unk_7FF550;
    *(int *)((char *)&dword_7FF678[3] + *(_DWORD *)(dword_7FF678[0] + 4)) |= 2u;
    v5 = 6;
    if ( dword_7FF4C0 )
      sub_5CFE4F(&unk_7FF588, 1, 1, 1);
    *(int *)((char *)&dword_7FF4EC + *(_DWORD *)(dword_7FF4C0[0] + 4)) = (int)&unk_7FF550;
  }
  return this;
}
