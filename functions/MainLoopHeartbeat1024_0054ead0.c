void MainLoopHeartbeat1024()
{
  int *v0; // esi
  int v1; // edi

  v0 = &dword_8CBF48;
  v1 = 1024;
  do
  {
    v0 -= 6;
    EmptyStub_0170();
    --v1;
  }
  while ( v1 );
}
