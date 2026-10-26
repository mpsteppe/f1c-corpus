std::_Winit *__thiscall std::_Winit::_Winit(std::_Winit *this)
{
  char v1; // bl
  int *v4; // [esp+Ch] [ebp-10h] BYREF
  int v5; // [esp+18h] [ebp-4h]

  v4 = 0;
  std::_Lockit::_Lockit((std::_Lockit *)&v4);
  if ( dword_628CEC < 0 )
  {
    dword_628CEC = 1;
    v1 = 1;
  }
  else
  {
    ++dword_628CEC;
    v1 = 0;
  }
  std::_Lockit::~_Lockit((std::_Lockit *)&v4);
  if ( v1 )
  {
    v4 = (int *)&unk_7FF7C0;
    v5 = 0;
    if ( &unk_7FF7C0 )
      sub_5D112B(&off_6253F8);
    v4 = (int *)&unk_7FF768;
    v5 = 1;
    if ( &unk_7FF768 )
      sub_5D112B(&File);
    v4 = (int *)&unk_7FF850;
    v5 = 2;
    if ( &unk_7FF850 )
      sub_5D112B(&unk_625438);
    v4 = &dword_7FF728;
    v5 = 3;
    if ( &dword_7FF728 )
      sub_5D1064(&unk_7FF7C0, 1, 1);
    v4 = (int *)&unk_7FF818;
    v5 = 4;
    if ( &unk_7FF818 )
      sub_5D0F90(&unk_7FF768, 1, 1, 1);
    *(int *)((char *)&dword_7FF728 + *(_DWORD *)(dword_7FF728 + 4) + 44) = (int)&unk_7FF818;
    v4 = dword_7FF6B0;
    v5 = 5;
    if ( dword_7FF6B0 )
      sub_5D0F90(&unk_7FF850, 1, 1, 1);
    v4 = dword_7FF6F0;
    *(int *)((char *)&dword_7FF6B0[11] + *(_DWORD *)(dword_7FF6B0[0] + 4)) = (int)&unk_7FF818;
    *(int *)((char *)&dword_7FF6B0[3] + *(_DWORD *)(dword_7FF6B0[0] + 4)) |= 2u;
    v5 = 6;
    if ( dword_7FF6F0 )
      sub_5D0F90(&unk_7FF850, 1, 1, 1);
    *(int *)((char *)&dword_7FF71C + *(_DWORD *)(dword_7FF6F0[0] + 4)) = (int)&unk_7FF818;
  }
  return this;
}
