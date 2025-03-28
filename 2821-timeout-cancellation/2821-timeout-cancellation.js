/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
const cancellable = function(fn, args, t) {
    // call setTimeout, which is set to call fn after t amount of time
    const timeoutId = setTimeout(() =>
        fn(...args)
    , t)

    // define a clearTimeout
    const cancelFn = () => clearTimeout(timeoutId);

    // When/if we call the function, it will return cancelFn,
    // and since the return line calls (and consequentially executes)
    // cancelFn, timeout will be cancelled, thereby cancelling fn
    return cancelFn;
    
};

/**
 *  const result = [];
 *
 *  const fn = (x) => x * 5;
 *  const args = [2], t = 20, cancelTimeMs = 50;
 *
 *  const start = performance.now();
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr)});
 *  }
 *       
 *  const cancel = cancellable(log, args, t);
 *
 *  const maxT = Math.max(t, cancelTimeMs);
 *           
 *  setTimeout(cancel, cancelTimeMs);
 *
 *  setTimeout(() => {
 *      console.log(result); // [{"time":20,"returned":10}]
 *  }, maxT + 15)
 */