void __thiscall sub_577380(int this)
{
  _DWORD *v1; // eax

  if ( dbl_FB1D18 > *(float *)(this + 19220) + 4.5 )
  {
    *(float *)(this + 19220) = dbl_FB1D18;
    if ( dword_82F4A0 >= 1023 )
    {
      v1 = (_DWORD *)off_9034A4;
    }
    else
    {
      ++dword_82F4A0;
      v1 = (_DWORD *)off_9034A4;
      off_9034A4 += 848;
    }
    sub_51B2A0(v1, 2, 0, 0, *(_DWORD *)(this + 4), *(_DWORD *)(this + 15932), 0);
  }
}
