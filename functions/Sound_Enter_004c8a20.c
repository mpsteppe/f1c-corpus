int __thiscall sub_4C8A20(int *this)
{
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_24, 661) )
    DebugLogWrite(&dword_8AD25C, aEnteredSoundEn);
  if ( !InitWithStatusCheck() )
    sub_4C82F0();
  sub_4C83B0(this);
  LazyAudioResourceInit();
  GlobalDispatchWithGuard(SLODWORD(flt_7CF380));
  LazyRendererAudioInitCheck((int)flt_5EA618);
  SceneGraphQuery(0);
  SceneGraphQuery(1);
  return 0;
}
