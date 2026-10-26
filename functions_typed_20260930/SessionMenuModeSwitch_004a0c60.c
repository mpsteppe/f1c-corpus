int sub_4A0C60()
{
  if ( ByteFieldExtractorWithShift(&dword_5EA43C) )
  {
    dword_7C569C = 6;
    MainMenuTransition(&dword_5EA43C);
    return 0;
  }
  else
  {
    if ( !dword_7CE814 )
    {
      ReciprocalWithSignCheck((int)&flt_5EA4E8, 0.5);
      GlobalStateOneTimeInitializer(&unk_7CE24D);
    }
    return 0;
  }
}

