int __thiscall sub_4945A0(void *this)
{
  int v2; // eax

  if ( !CINet::DownloadStarted((CINet *)dword_B6CBB0) || CINet::DownloadInProgress((CINet *)dword_B6CBB0) )
  {
    LOBYTE(v2) = 1;
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, v2);
    return 0;
  }
  else
  {
    LOBYTE(v2) = 0;
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, v2);
    return 0;
  }
}
