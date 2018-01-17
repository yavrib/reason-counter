type action =
  | INCREASE
  | DECREASE;

type state = {
  count: int
};

/* This is the basic component. */
let component = ReasonReact.reducerComponent("Counter");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log(_self);

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
let make = (_children) => {
  ...component,
  initialState: () => { count: 0 },
  reducer: (action, state) => {
    switch action {
      | INCREASE => ReasonReact.Update({...state, count: state.count+1})
      | DECREASE => ReasonReact.Update({...state, count: state.count-1})
    };
  },
  render: (self) =>
    <div>
      <div onClick=(self.handle(handleClick))> (ReasonReact.stringToElement(string_of_int(self.state.count))) </div>
      <button onClick={_event => self.send(INCREASE)}>(ReasonReact.stringToElement("Increase"))</button>
      <button onClick={_event => self.send(DECREASE)}>(ReasonReact.stringToElement("Decrease"))</button>
    </div>
};
