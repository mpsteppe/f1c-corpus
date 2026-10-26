void sub_4FB200()
{
  int v0; // eax

  v0 = 0;
  if ( (int)NumOfElements > 0 )
  {
    while ( *(_DWORD *)(dword_75AAD0[v0] + 20892) )
    {
      if ( ++v0 >= (int)NumOfElements )
        return;
    }
    sub_4DC390((_DWORD *)(dword_75AAD0[v0] + 20836));
  }
}
