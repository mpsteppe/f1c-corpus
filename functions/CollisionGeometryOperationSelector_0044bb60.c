int __thiscall sub_44BB60(void *this, int a2, char **a3)
{
  int v3; // esi
  char *v6[5]; // [esp+Ch] [ebp-14h] BYREF

  v3 = dword_8AFE88;
  if ( dword_8AFE88 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        AnimationPlaybackSequence(this, dword_8AFE88, a3);
        CollisionContactResponse((int *)a3);
        return SweepAndPruneAABBOverlapDetection((int *)a3);
      }
      if ( a2 == 2 )
      {
        CollisionShapeInit(v6);
        AnimationPlaybackSequence(this, v3, v6);
        CollisionContactResponse((int *)v6);
        BezierPatchTessellation(this, (int *)v6, a3);
        PhysicsBufferFree(v6);
        return SweepAndPruneAABBOverlapDetection((int *)a3);
      }
    }
    else
    {
      AnimationPlaybackSequence(this, dword_8AFE88, a3);
    }
  }
  return SweepAndPruneAABBOverlapDetection((int *)a3);
}
