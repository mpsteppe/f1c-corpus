int setSBCS()
{
  int result; // eax

  memset(&byte_FBB280, 0, 0x100u);
  unk_FBB380 = 0;
  result = 0;
  dword_FBB384 = 0;
  dword_FBB264 = 0;
  dword_FBB25C = 0;
  *(_DWORD *)&word_FBB390 = 0;
  *(_DWORD *)&algn_FBB392[2] = 0;
  *(_DWORD *)&algn_FBB392[6] = 0;
  return result;
}
