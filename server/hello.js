const request = require("request");
require("dotenv").config();

const key = process.env.YOUTUBE_API_KEY;
const videoId = process.env.VIDEO_ID;
// const chatId = process.env.LIVE_CHAT_ID;

const getVideosList = (key, videoId) => {
  const URL = "https://www.googleapis.com/youtube/v3/videos";
  const Part = "liveStreamingDetails";

  request.get(
    {
      uri: URL,
      headers: { "Content-type": "application/json" },
      qs: {
        id: videoId,
        part: Part,
        key: key,
      },
      json: true,
    },
    function (err, req, data) {
      console.log(data);
      const chatId = data.items[0].liveStreamingDetails.activeLiveChatId;
      console.log(chatId);
      return chatId;
    }
  );
};

const getLiveChatMessages = (key) => {
  const URL = "https://www.googleapis.com/youtube/v3/liveChat/messages";
  const part = "id,snippet,authorDetails";
  const pageToken = process.env.PAGE_TOKEN;

  request.get(
    {
      uri: URL,
      headers: { "Content-type": "application/json" },
      qs: {
        liveChatId:
          "Cg0KC2hNY084UndTWm1vKicKGFVDYlZ3ZEVRcFMtbVZlc1UtVk5yRWl6ZxILaE1jTzhSd1NabW8",
        part: part,
        key: key,
        // pageToken: pageToken,
      },
      json: true,
    },
    function (err, req, data) {
      console.log(data);
      console.log(data.items[0].snippet.displayMessage);
    }
  );
};

const videosList = getVideosList(key, videoId);
console.log(videosList);
const chatId = videosList;
console.log(chatId);
const liveChatMessages = getLiveChatMessages(key);
// console.log(liveChatMessages);
// console.log(liveChatMessages.toJson);
