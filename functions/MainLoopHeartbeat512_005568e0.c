void MainLoopHeartbeat512()
{
  int *v0; // esi
  int v1; // edi

  v0 = &dword_8CEF70;
  v1 = 512;
  do
  {
    v0 -= 6;
    EmptyStub_0170();
    --v1;
  }
  while ( v1 );
}
