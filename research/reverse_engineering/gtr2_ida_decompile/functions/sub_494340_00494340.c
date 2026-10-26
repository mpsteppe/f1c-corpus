int __thiscall sub_494340(void *this)
{
  int v2; // eax

  if ( !CINet::UpdateAvailable((CINet *)dword_B6CBB0) || CINet::DownloadStarted((CINet *)dword_B6CBB0) )
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
