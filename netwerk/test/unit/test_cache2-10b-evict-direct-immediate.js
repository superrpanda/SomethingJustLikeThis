function run_test() {
  do_get_profile();

  asyncOpenCacheEntry(
    "http://b/",
    "disk",
    Ci.nsICacheStorage.OPEN_NORMALLY,
    null,
    new OpenCallback(NEW | DOOMED, "b1m", "b1d", function(entry) {
      entry.asyncDoom(
        new EvictionCallback(true, function() {
          finish_cache2_test();
        })
      );
    })
  );

  do_test_pending();
}
