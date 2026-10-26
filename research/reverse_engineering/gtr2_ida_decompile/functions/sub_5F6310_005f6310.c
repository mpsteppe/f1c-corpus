void sub_5F6310()
{
  if ( dword_910FEC != 256 )
  {
    qmemcpy(&unk_FB3EC0, &unk_FB2F78, 0x40u);
    (*(void (__stdcall **)(int, _DWORD, void *, int))(*(_DWORD *)dword_FB40C8 + 436))(dword_FB40C8, 0, &unk_FB2F78, 4);
    dword_FB3F10 = dword_FB2F58;
    dword_FB3F14 = dword_FB2F5C;
    dword_FB3F18 = dword_FB2F60;
    dword_FB3F1C = LODWORD(flt_FB2F64);
    (*(void (__stdcall **)(int, int, int *, int))(*(_DWORD *)dword_FB40C8 + 436))(dword_FB40C8, 5, &dword_FB2F58, 1);
  }
}
