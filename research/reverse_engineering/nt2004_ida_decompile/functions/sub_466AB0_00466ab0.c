HANDLE sub_466AB0()
{
  DWORD v0; // eax
  _DWORD *v1; // eax
  HANDLE result; // eax

  sub_466A60();
  sub_46C1D0(2);
  sub_466A60();
  if ( hMutex && ((v0 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v0 == 128) )
    v1 = &unk_764EDC;
  else
    v1 = 0;
  *v1 = 3;
  sub_466A60();
  result = hMutex;
  if ( hMutex )
    return (HANDLE)ReleaseMutex(hMutex);
  return result;
}
